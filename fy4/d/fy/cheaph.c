inherit ROOM;
void create()
{
    set("short", "���ι�");
    set("long", @LONG
һ���ª�ģ��������������ĵͰ�С���������ǽ�������ѷ죬�����Ͻ�һֱ
�ѵ���ߵ�ǽ���������һ�ź�������Ϊһ������������������ͷ���ź�
���ʣ�������ֽһ�ţ��۸���ƽ����Ů���ٽ��ˣ�ˡ����Ǯ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"stone1",
      ]));
    set("objects", ([
	__DIR__"npc/chick" : 1,
      ]) );
    set("no_preach",1);
    set("coor/x",260);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
