inherit ROOM;
void create()
{
    set("short", "�����֬��");
    set("long", @LONG
��������Ÿ�ʽ��������֬���дӾ��������ģ�Ҳ�б��ز��ġ���֬�ʺ���Ѫ,
�����˱ǡ�ÿ����������������������ڣ�ӳ����֬�ϣ�����һ��ҫ�۵����졣��
����֬���ﻹ���ٻ��ͣ����۴������ϰ���˵������ʮ�������������������ݸ��֡�
LONG
    );
    set("exits", ([
	"east" : __DIR__"swind31",
      ]));
    set("objects", ([
	__DIR__"npc/makeupseller": 1,
	__DIR__"npc/younggirl": 2,
	__DIR__"npc/youngman": 2,
      ]) );
    set("coor/x",-20);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
