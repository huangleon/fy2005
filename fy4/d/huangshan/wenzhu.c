// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
�ഫ�������ŷ�ʦ�������������������������Խ�����Ժ�����ʢ��һʱ����
ϧ������������а�������������ս���꼰����Ժ�����дӴ�һ�겻����������
�Կɴ�ǽ�ڵĺۼ�ң�뵱��һս�Ĳ��ҡ�
LONG
        );
    set("exits", ([ 
  "southeast"  : __DIR__"yingke",
  "north" : __DIR__"yixian",
	]));
        set("objects", ([
        __DIR__"npc/bing" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
