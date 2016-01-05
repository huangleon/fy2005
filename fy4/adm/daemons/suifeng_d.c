// /adm/daemons/action_d.c
// created by akuma@mud.com.cn
// on 2009-03-28
// ����飬������͹ر�ÿ�յĻ
// ���daemon�����������ɹ㲥���ͻ״̬������
// ������ʲôҲ����������ϵͳ���������ȡĳ����Ƿ�����״̬
// Ӧ�ñ�preload

#include <localtime.h>
#include <ansi.h>
#define DEFAULT_TIMES   200
#define HOLIDY_TIMES    300
void check_action_startend();

void create()
{
        check_action_startend();
}

void check_action_startend()
{
	mixed *ltime;
	int now_wday;
        int now_hour;
        int times;

	ltime = localtime(time());
	now_wday = ltime[LT_WDAY]; //��ǰ���ӣ�����Ҫ��localtime(��ȡ����ʱ��)
        now_hour = ltime[LT_HOUR];
	
	//Ϊ�˱��գ���remove�Լ���call_out
	remove_call_out("check_action_startend");
	
        times = DEFAULT_TIMES;
        if (now_wday == 5) {
                if (now_hour >= 15) {
                        times = HOLIDY_TIMES;
                }
        } else if (now_wday == 1) {
                if (now_hour < 3) {
                        times = HOLIDY_TIMES;
                }
        } else if (now_wday == 6 || now_wday == 0) {
                        times = HOLIDY_TIMES;
        }
        "/adm/daemons/questd"->set_holiday(times);
	call_out("check_action_startend",60);
}

