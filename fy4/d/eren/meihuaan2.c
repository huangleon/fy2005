inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��Ժ");
        set("long", @LONG
����������̦��ʯ�ף�����һ�ƣ��аܵĴ��ž͡�ѽ����һ�����ˣ���������
�������ǵ�̾Ϣ��Ժ�������Ҷ�ܺ񣬺������綼������һ����ͳ����о�����
������磬�����������Ժ�䡣�������ïʢ��÷���֣���ʮ����ǰ��Ѫ��������
���ѱ�����������
LONG
        );
        set("exits", ([ 
		"out": __DIR__"meihuaan",
		"north": __DIR__"meihuaan3",
	]));
        set("objects", ([
		
	]) );
	set("coor/x",-10);
        set("coor/y",20);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
