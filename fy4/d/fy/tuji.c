inherit ROOM;
void create()
{
    set("short", "��������");
    set("long", @LONG
��ϡϡ��ľ���Ϸ��ż�����ɫ�Ұ���������Ŀ�����⡣һ����ͷ��Ӭææµµ
�ķ�����䡣����������������Ϲ��Ű����˵���ͷ����ͷ����ţͷ����̨����
�Ƕ����ż���ľϻ��ϻ�з���Щ�����˵�������Źǡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"lssquare2",
      ]));
    set("objects", ([
	__DIR__"npc/butcher" : 1,
      ]) );

    set("coor/x",160);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
