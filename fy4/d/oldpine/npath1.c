// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·��������Զ���߳��������Ӿ��������裬С·��
�Գ����������ʵ���������Χ�ľ��񶼰���������������֡�����˵����������
������ǧ�����������������顣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"npath2",
  "west" : AREA_TAISHAN"mengxian",
]));
        set("outdoors", "oldpine");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
