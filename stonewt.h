#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
	private:
		enum {Lbs_per_stn = 14};
		int stone;
		double pds_left;
		double pounds;
	public:
		Stonewt(double lbs);
		Stonewt(int stn, double lbs);
		Stonewt();
		~Stonewt();
		void show_lbs() const;
		void show_stn() const;
		double show_pds_left();
		double show_pounds();
		int show_stone();
};
#endif