inherit ROOM;
void create()
{
        set("short", "ü��۶�¥");
        set("long", @LONG
վ�������С���Ϳ��Կ������������ķ����ڷ���ҡҷ����������������
Զ��������һƬ÷�֡�÷����¶��һ��С¥������С��ɵ����ն���ѧ���ĵط���
÷�������·�ȼ���ǰ���ĸ�ʤ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" :   __DIR__"yitea",
]));
        set("objects", ([
	__DIR__"npc/lson" : 1,
	__DIR__"npc/ximen" : 1,
                        ]) );

	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
