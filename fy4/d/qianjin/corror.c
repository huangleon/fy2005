inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ÿ���岽�����Ҹ�һ�š��������мǺţ��ź�����������ÿ��ʮ�������һյ��
��������������ϸ�������ƺ�ÿ���տա�����������������ǰ��չ��һ����������
ͷ��ÿ�������沨ҡ�ڣ��������εĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wting",
  "west" : __DIR__"corror1",
]));

	set("coor/x",-75);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}