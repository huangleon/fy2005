// searoad.c
inherit ROOM;
void create()
{
        set("short", "���¶�");
        set("long", @LONG
������ժ�Ƿ���¶�������һ����ʯƽ̨������Χ���������ˣ���������ɽ����
����ֱ�䣬����ƽ̨ӳ�ø��ǻԻͲ��á�����������ŮΧ���������ԣ�������һ��
����ɫ����ϯ������΢����⣬Ҳ��֪��ʲô֯�ɡ�һ�����¸���б����ϯ�ϣ�Զ
���ź��󣭣���Ŀ��ȥ�������������ƣ�����������ӳ�һƬ��̡�
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl2" : 1,
        	AREA_TIEFLAG"npc/qinggirl3" : 2,
        	AREA_TIEFLAG"npc/master2"  : 1,
        ]) );
        set("exits", ([ 
	  	"westdown" : __DIR__"uproad4",
        
		]));
		set("valid_startroom",1);
        set("outdoors", "tieflag");
	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}
