inherit ROOM;
void create()
{
        set("short", "�����ۼװ�");
        set("long", @LONG
��ɫ���̣���ɫ������΢���������羰���ˡ�һ������ȭ�о��������Ů��
�Ľ�Ц����ʱ�ĴӴ����д���������ϸ�����������ƺ��������ŵ͵͵ı���֮����
�봬�ϵĻ���Ц�Ｋ����Ǣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"boat2",
  "south" : __DIR__"tading",
]));
	set("outdoors","fengyun");
        set("objects", ([
        __DIR__"npc/qiudu" : 1,
                        ]) );

	set("coor/x",-65);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
