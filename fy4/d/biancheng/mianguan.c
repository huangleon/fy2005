inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���");
        set("long", @LONG
��ݵ��ϰ�������ʵ������ʵ����Ǹ���ʵ�ˣ�����������С��ݵ��ϰ壬Ҳ
�ǳ��Ӻͻ�ƣ�����һ�굽ͷ����������Χ�ſ��������Χȹ��������һֱæ����
�ڣ�׬����Ǯȴ�������Ŷ������𡣵�����������Ц�����ģ������ֻȥ����һ��
����Ǯ�������棬���������㵱����үһ���չˡ����������������񽬺���Ҳ��
��û������Թ��䡣
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"sstreet1",
	]));
        set("objects", ([
        	__DIR__"npc/bosszhang":	1,
	]) );
        set("coor/x",-20);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	
}

void reset(){
	if (present("pan ling",this_object()))	return;
	::reset();
}	