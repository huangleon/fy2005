inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
����������Ҳ�����ӵİ׾ơ�һ���Ѿ����糶�ѵľ����ϻ���һ���ï޺�Ȧ������
���ơ��֡�������ͳ���һ��ҵ�ѱ�ڵİ׷������ײ��·��ż����ƾɵ�ľ���ͷ��ʣ�
ľ��������ɢɢ�÷��ż�˫ľ��ͼ������˿ڵ�С������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );

        set("coor/x",-50);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
