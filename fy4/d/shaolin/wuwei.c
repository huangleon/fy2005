// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ϊ¥");
        set("long", @LONG
һ���ľС¥����ǰ�Ҷ��ϡ���Ϊ�������뱱����徲¥ң���Ӧ��¥��ֻ��
һ�Ų輸��һֻС��¯���������˱��ǲ�����֣���ǽ��������һ�ѣ����ʹ�ɫ��
�㣬һ����֪���Ƿ�Ʒ����ǽ��һ�������

			[37m��������[32m

LONG
        );
        set("exits", ([ 
  			"north" : __DIR__"diyuan",
		]));
        set("objects", ([
                __DIR__"npc/girlfy": 1,
       ]) );
		set("coor/x",-20);
		set("coor/y",110);
		set("coor/z",20);
		setup();
        replace_program(ROOM);
}
