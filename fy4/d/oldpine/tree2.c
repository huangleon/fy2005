// Room: /d/oldpine/tree2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ʸ���һ��������������ϣ�����������Ѿ����ߡ����ɸߣ������
С�ĵ�����ȥ����������Ҳ��ȥ�������������Ͻ�������ɹ��������󲿷ֶ�����
�ɺ�Զ���㹻������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree3",
  "down" : __DIR__"tree1",
]));

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}
