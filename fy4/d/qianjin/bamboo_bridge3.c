inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ͻ���Ǿޱ��ľ�㡢��÷����ȸ�������������ɡ����ڡ�������֡�����
�ǽ��桢�ٺϡ������ޡ������ޡ����ؽ�����֦ĵ�����࣬����ö�١�������֮ʱ��
�����������Զ�����ߣ���ֲ������ݡ�һ��δл��һ���ֿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hehuadang",
  "northeast" : __DIR__"bamboo_bridge2",
]));
        set("objects", ([
        __DIR__"npc/yahuan" : 2,
                        ]) );
	set("outdoors","fengyun");
	set("coor/x",-20);
	set("coor/y",-5);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
