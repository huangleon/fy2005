// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������й�����һ����������ܴ����ᣣ�һ�ų����Ϲ������ʻ���ˮ����
�м���һ��¯��������������㣬����ɫ�������������ǻ������ڵ�����֮�䣬��
�ڵ�һ�ж���������һ�㱡ɴ����ǰ�ĵ��ϰ��ż������ţ��Ա߷��ż���ľ�㡣       
LONG
        );
	set("exits", ([ 
    	"north" : __DIR__"yard",  
	]));
    	set("objects", ([
        	__DIR__"npc/nun" : 2,
    		__DIR__"npc/master": 1,
    	]) );
    	set("indoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-40);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
