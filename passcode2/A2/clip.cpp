int clip(int value){
	if (value < PURE_BLACK) return PURE_BLACK;
	if (value > PURE_WHITE) return PURE_WHITE;
	return value;
}