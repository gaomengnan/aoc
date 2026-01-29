# Agent Guidelines for BST Check Repository

## Build/Lint/Test Commands
- Run main script: `python main.py`
- Run tests: `python test_bst.py` or `python -m unittest test_bst.py`
- Run single test: `python -m unittest test_bst.TestBST.test_valid_bst`
- No lint framework configured - consider mypy for type checking

## Code Style Guidelines
- Use snake_case for function and variable names
- Use PascalCase for class names
- 4-space indentation
- Type hints required for all function parameters and return types
- Use Optional[Type] for nullable types
- Error handling: validate inputs, handle None cases
- Imports: organize at top, use typing module for type hints
- Keep functions small and single-purpose
- Use float("-inf") and float("inf") for BST bounds checking