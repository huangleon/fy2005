inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
���߾��Ǹߴ�ķ��Ƴǣ�һ·�����˱ȼ磬�ϸ账����С·����������һ����
���������̲��羵��������ˮ������֮����ֱ�����ɾ��ء����Ķ����ש���ߣ���
�Ǹ����˼ҵ�ׯ԰����������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"fysouth",
  		"northwest": __DIR__"sroad2",
		"southwest": __DIR__"lake",
	]));
        set("outdoors", "fengyun");
	set("coor/x",-120);
	set("coor/y",-320);
	set("coor/z",0);
        setup();
}

