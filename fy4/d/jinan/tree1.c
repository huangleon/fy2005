// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ʸ���һ������������ϣ���������Ժ�������������µ�һ�ж�
�����������˷������ƺ��Ǹ���͵�����������ĺõط���
LONG
        );
        set("objects", ([
                AREA_QIANFO"npc/spy":1 ,
		AREA_QIANFO"npc/maque" : 2,
	]) );

        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tanghuai",
]));

	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
