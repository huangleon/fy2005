inherit ROOM;
void create()
{
    set("short", "����С��");
    set("long", @LONG
����С��ش����ǣ������������������ӣ���ͷ�߽ᵳ��Ⱥ������˵Ҳ�в���
������������ڴˡ������ﵽ���������ӵĽ�����������˷���ߺ��������һЩ��
�Źֵ��������������д򶷵�е��ײ�����죻���������ϸ���Ʈ���Ÿ�ʽ������ζ
������ģ����ģ�˵�ó��ģ�˵�����ġ�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"stone1",
	"east" : __DIR__"futhur",
	"south" : __DIR__"yulong3",
	"northwest" : __DIR__"lssquare3",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
