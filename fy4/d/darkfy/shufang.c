inherit ROOM;
void create()
{
        set("short", "֪���鷿");
        set("long", @LONG
������ͥ���鳨�����й�һ������ɽˮ����һ����ͭ��¯��¯������Ʈ�졣���
��һ��������齣��ұ߼��϶�������ͼ�顣�ش�һֻ���ϣ������ķ��ı�������ͥ��
��ֲ��໨ľ�������ʮ�����ţ�����͢���ٶ������ⷢ��������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"govern",
]));
        set("objects", ([
        __DIR__"npc/governor" : 1,
                        ]) );

        set("coor/x",-19);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
}

