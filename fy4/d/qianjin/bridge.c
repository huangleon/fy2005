inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�ɻ����ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬����
��Ӱө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ
�ʣ�«έ�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"hehuadang2",
  "west" : __DIR__"bridge1",
]));
        set("objects", ([
        __DIR__"npc/chong" : 3,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
