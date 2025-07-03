#!/usr/bin/env python3
import os
import string
import argparse


def generate_structure(start_idx: int, end_idx: int, base_name: str, end_char: str) -> None:
    """
    Generate directories from base_name+start_idx to base_name+end_idx,
    each containing .cpp files from a/A up to end_char.
    """
    # Validate end_char
    if len(end_char) != 1 or not end_char.isalpha():
        raise ValueError("End character must be a single alphabet letter.")

    # Determine letter range based on case
    letters = string.ascii_lowercase if end_char.islower() else string.ascii_uppercase

    # Slice letters up to the specified end_char
    try:
        idx = letters.index(end_char) + 1
        target_letters = letters[:idx]
    except ValueError:
        raise ValueError(f"Character '{end_char}' not in expected alphabet range.")

    # Loop through folder indices
    for i in range(start_idx, end_idx + 1):
        folder_name = f"{base_name}{i}"
        os.makedirs(folder_name, exist_ok=True)

        # Create files in each folder
        for ch in target_letters:
            file_path = os.path.join(folder_name, f"{ch}.cpp")
            with open(file_path, 'w') as f:
                f.write(f"// {ch}.cpp in {folder_name}\n")

    print(f"Generated folders {base_name}{start_idx} to {base_name}{end_idx} with files up to '{end_char}'.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate directory structure with .cpp files up to a specified character."
    )
    parser.add_argument('start_idx', type=int, help='Starting index for folder naming')
    parser.add_argument('end_idx', type=int, help='Ending index for folder naming')
    parser.add_argument('base_name', type=str, help='Base name for folders')
    parser.add_argument('end_char', type=str, help='End character (single letter) for file naming')
    args = parser.parse_args()

    try:
        generate_structure(args.start_idx, args.end_idx, args.base_name, args.end_char)
    except Exception as e:
        print(f"Error: {e}")
        exit(1)
