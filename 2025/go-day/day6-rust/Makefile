# Makefile

# 项目变量
BUILD_DIR=./package FRONTEND_DIR=../New_Tracker_Frontend
TRACKER_DIR=../Tracker_new
MIGRATE_DIR=$(TRACKER_DIR)/migrate
JOB_DIR=$(TRACKER_DIR)/job
MODE=stage

# Git 信息
CURRENT_BRANCH=$(shell git rev-parse --abbrev-ref HEAD)
LAST_COMMIT_HASH=$(shell git rev-parse --short HEAD)

.PHONY: all build clean build_frontend build_migrate build_tracker build_job

all: build

build: confirm
	@echo "Building for environment: $(inputEnv)"
	@if [ "$(inputEnv)" != "windows" ] && [ "$(inputEnv)" != "linux" ]; then \
		echo "Invalid environment: $(inputEnv). Must be 'windows' or 'linux'."; \
		exit 1; \
	fi

	@echo "Creating build directory: $(BUILD_DIR)/$(inputVersion)"
	@rm -rf $(BUILD_DIR)/$(inputVersion)
	@mkdir -p $(BUILD_DIR)/$(inputVersion)

	@$(MAKE) build_frontend
	@$(MAKE) build_migrate
	@$(MAKE) build_tracker
	@$(MAKE) build_job

	@echo "Build completed."

confirm:
	@echo "Current branch: $(CURRENT_BRANCH)"
	@echo "Last commit hash: $(LAST_COMMIT_HASH)"
	@read -p "Confirm build for branch $(CURRENT_BRANCH) with last commit hash $(LAST_COMMIT_HASH)? [y/N]: " confirm && [ $${confirm} = y ]

build_sample:
	@echo "build tracker"
	cd ../New_Tracker_Frontend && git pull && npm run build:stage -- --dest=../Tracker_new/tracker/public/tracker
	@echo "success"

# build_called:
# 	@echo "build called"
# 	cd ../QMS_Frontend/called && npm run build:$(MODE)
# 	@echo "success"
#
# build_called_screen:
# 	@echo "build called_screen"
# 	cd called_screen && npm run build:$(MODE)
# 	@echo "success"

build_frontend: build_sample
	@echo "Building frontend..."

build_migrate:
	@echo "Building migrate..."
	@cd $(MIGRATE_DIR) && \
		rm -f ./data/bindsql.go && \
		go-bindata -pkg data -o data/bindsql.go ../sql/site/update/ ../sql/site/table/ ../sql/site/procedures/ ../sql/sys/update/ ../sql/sys/table/ && \
		cp ./data/bindsql.go ../tracker/data/ && \
		go build -ldflags "-X main.Version=$(inputVersion)" -o $(BUILD_DIR)/$(inputVersion)/MigrateConfig$(FILE_EXT) main.go

build_tracker:
	@echo "Building tracker..."
	@cd $(TRACKER_DIR)/tracker && \
		cp start.sh $(BUILD_DIR)/$(inputVersion) && \
		cp stop.sh $(BUILD_DIR)/$(inputVersion) && \
		mkdir -p $(BUILD_DIR)/$(inputVersion)/config && \
		cp ./config/settings.config.yml $(BUILD_DIR)/$(inputVersion)/config/ && \
		cp ./config/rbac_model.conf $(BUILD_DIR)/$(inputVersion)/config/ && \
		mkdir -p $(BUILD_DIR)/$(inputVersion)/download && \
		cp -r ./download/* $(BUILD_DIR)/$(inputVersion)/download && \
		mkdir -p $(BUILD_DIR)/$(inputVersion)/public && \
		cp -r ./public/* $(BUILD_DIR)/$(inputVersion)/public && \
		go build -ldflags "-X main.Version=$(inputVersion) -X main.GitBranch=$(CURRENT_BRANCH) -X main.LastCommitHash=$(LAST_COMMIT_HASH)" -o $(BUILD_DIR)/$(inputVersion)/tracker$(FILE_EXT)

build_job:
	@echo "Building job..."
	@cd $(JOB_DIR) && \
		go build -ldflags "-X main.Version=$(inputVersion)" -o $(BUILD_DIR)/$(inputVersion)/jobService$(FILE_EXT)

clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean completed."

run:
	GOROOT=/Users/wanglele/.goenv/versions/1.17.13/
	cd tracker && go run . server -c=/opt/wwwroot/air/dockers/tracker/config/settings.2_test1.yml


attach:
	@echo "Running attach command"
	ps -ef | grep __tracker2.0 | grep -v 'grep' | awk '{print $$2}' |  xargs -I {} dlv --log --continue --accept-multiclient --listen=:23452  --headless=true --api-version=2 attach {}
