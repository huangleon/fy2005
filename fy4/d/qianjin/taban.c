inherit ROOM;
void create()
{
        set("short", "����̤��");
        set("long", @LONG
������ǰ��һ���޴��˫��ľ����������Φ�޷�����Ȼ�ǳ���ͣ���������
�ϵƻ�ͨ�����������С�΢�紵����ϸ�����ϣ������н���ġ�žž����������Ҳ
��֮΢��΢����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lastbridge",
  "west" : __DIR__"boat",
]));
	set("outdoors","fengyun");
	set("coor/x",-55);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
