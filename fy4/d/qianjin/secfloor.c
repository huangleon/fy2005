inherit ROOM;
void create()
{
        set("short", "�����۶���");
        set("long", @LONG
Ӧ��������������һ��ռ����һ��ǽ�Ĵ���ͼ������Ϊ��������������ϸ�壬
�������֡���յ�񱭣�������칹����һ�����ص�в���������з��ż�����ʯԲ����
���ϱ�յ�β����������ǧ��¥���Ĳ��߸�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"stairs2",
  "northup" : __DIR__"jinge",
]));
        set("objects", ([
        __DIR__"npc/dapiaoke" : 1,
	__DIR__"npc/dachick": 1,
                        ]) );

	set("coor/x",-65);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
