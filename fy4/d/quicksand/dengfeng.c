// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Ƿ��س�");
        set("long", @LONG
��ʯ�ֵ�����Խ��Խ�ӽ�ɽ����ÿ������������������������οͼ��࣬����
��Ϊ������ɽ�ؾ�֮·�ĵǷ��سǷ�������֣���·���ߵ�����������ɽ�����һ
�У�����Ӧ�о��С���·��������һ�����̺�һ�Ҳ��̡�����������ɽ�����ܴ��
·����д��[33m����ɽ�����¡�[32m�ɴ�ǰ�С�
LONG
        );
        set("exits", ([ 
  		"east" : "/d/fycycle/fywest",
  		"west" : __DIR__"xiaodao1",
  		"northwest" : AREA_SONGSHAN"qimu",
  		"southeast" : __DIR__"bupu",
  		"southwest" : __DIR__"tiepu",
]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-600);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
