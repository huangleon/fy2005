// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ȹ��");
        set("long", @LONG
����һ������ש��ɵķ��ӣ��������ĸ��������ӣ�����֮�����һ�ԭ��
���й�������Ϣ�������Ѳ�֪ȥ�򡣷��ӵ�ǽ�Ͽ��˺ܶ��洰����͸���񻨵Ĵ���
���������ؿ������ܵľ�ɫ���Ŵ��ţ�����һ�����顰�ȹ�󡱣���������ʯ��
�̳ɵ�̨�ӡ�
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"taohua",
]));
        set("objects", ([
                __DIR__"npc/feng" : 1,
		__DIR__"npc/jin" : 1,
       ]) );

        set("indoors", "huangshan");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
