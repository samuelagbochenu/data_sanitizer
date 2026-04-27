"""
Data Sanitizer Utility (Python)
Author: Samuel
Description: A utility function to clean and standardize a mixed-type list. 
Demonstrates type checking, string manipulation, and edge-case handling.
"""

def sanitize_data(raw_data: list) -> list:
    """
    Cleans a list of mixed data types.
    
    Args:
        raw_data (list): A list containing mixed data types (str, int, float, None).
        
    Returns:
        list: A cleaned list with standardized formatting.
    """
    # Guard clause: Check if the input is actually a list
    if not isinstance(raw_data, list):
        raise TypeError("Input must be a list.")
        
    # Guard clause: Return empty list if input is empty
    if len(raw_data) == 0:
        return []

    cleaned_data = []
    
    for item in raw_data:
        # Skip None or empty string values
        if item is None or item == "":
            continue
            
        # Handle Strings: Strip whitespace and capitalize, or convert to int if numeric
        if isinstance(item, str):
            stripped_item = item.strip()
            if stripped_item.isdigit():
                cleaned_data.append(int(stripped_item))
            else:
                cleaned_data.append(stripped_item.capitalize())
                
        # Handle Numbers: Pass them through directly
        elif isinstance(item, (int, float)):
            cleaned_data.append(item)

    return cleaned_data

# ==========================================
# Testing the Logic
# ==========================================
if __name__ == "__main__":
    messy_input = ["  apple ", None, 42, "100", "", "  BANANA  ", 3.14, ["nested", "list"]]
    
    print("Original Data:", messy_input)
    try:
        clean_output = sanitize_data(messy_input)
        print("Cleaned Data: ", clean_output)
    except TypeError as e:
        print(f"Error: {e}")
