class Circle{
	private:
		int radius;
		
	public:
		Circle();
		Circle(int);
		~Circle();
		void setRadius(int inRadius);
		int getRadius();
		float calculatearea();
		static float PI;
};
