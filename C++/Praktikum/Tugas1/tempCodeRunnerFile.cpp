
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(arr[mid].name, keyword);
        
        if (res == 0) { // Cocok
            printf("[FOUND] %s (%d) - Rating: %.1lf\n