inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��ϡϡ��ľ���Ϸ��ż�����ɫ�Ұ���������Ŀ�����⡣һ����ͷ��Ӭææµµ��
������䡣����������������Ϲ��Ű����˵���ͷ����ͷ����ţͷ����̨����Ƕ�
���ż���ľϻ��ϻ�з���Щ�����˵�������Źǡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
