
inherit ROOM;

void create()
{
        set("short", "���˶�");
        set("long", @LONG
�����ȵ�һ������һ��С·��С·����һ��ʯ��������ʯ����ֻ����ľ�״У�
�滨���ף�һ���������ӻ�ľ�к��ʯ϶֮�¡�������֮��������Ϫк��ʯ
���ƣ���ʯΪ�����������ӣ�ʯ�����ۣ��������¡�
LONG
        );
        set("exits", ([ 
  		"southdown" : __DIR__"palace_front",
	]));
        set("objects", ([
               __DIR__"npc/master2" : 1,
       ]) );
        set("valid_startroom", 1);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

