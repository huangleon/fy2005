// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ѩͤ");
        set("long", @LONG
�ֳƴ�Ħͤ���ǵ���������Ϊ��𷨣������Ħ��ѩû˫ϥ�ĵط������ڽ�
������ССͤ�ӣ���������ѩû˫ϥ֮�ࡣ���з��裬��Ǭ¡���⡰ѩӡ���顱��
���б��ļ���������ѩ�ϱ۵Ĺ��¡��ɴ��򱱣��㵽�˺����
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lishi",
  "southdown" : __DIR__"fang",
  "west" : __DIR__"tayuan",
]));
        set("objects", ([
                __DIR__"obj/fuohe" : 1,
                __DIR__"npc/laomonk2" :1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
        if(!this_player()->query_temp("see_fangzhang"))
                set("exits/southdown", __DIR__"fangnan");
	else
		set("exits/southdown", __DIR__"fang");
}
