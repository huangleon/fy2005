inherit ROOM;
void create()
{
    set("short", "����С��");
    set("long", @LONG
����С��ش����ǣ������������������ӣ���ͷ�߽ᵳ��Ⱥ������˵Ҳ�в���
������������ڴˡ������ﵽ���������ӵĽ�����������˷���ߺ��������һЩ��
�Źֵ��������������д򶷵�е��ײ�����죻���������ϸ���Ʈ���Ÿ�ʽ������ζ
������ģ����ģ�˵�ó��ģ�˵�����ģ������������ӵ����߹㳡��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"lssquare1",
	"south" : __DIR__"yulong1",
      ]));
    set("objects", ([
	__DIR__"npc/oho" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",80);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
