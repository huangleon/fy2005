inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������־�ڻ�;�ķ��������˶�Ҫ������ͨ����һ�ο��ԡ�����˫ȫ��ǰ�����ᱻ
���뾩�����ԡ�ÿ��һ��һ�ȵĿ���������ͻ���ɽ�˺��������ֵıȲο��Ļ��ࡣ��
�Ƶ���һ����������ӳ��������Է��Ƴ�ÿ�궼���˲ű�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
	__DIR__"npc/" : 3,
                        ]) );

        set("coor/x",-10);
        set("coor/y",-1);
        set("coor/z",-300);
        setup();
}
