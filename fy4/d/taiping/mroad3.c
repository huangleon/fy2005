// seaside.c
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
�ֵ����������˷����������������ľ�����һ������Ҷ��糺�������������
�糯¶���������ݵ���֬��С��������֬���Գ���֮�£�����������ļ��ˡ����
�������¹��Ÿ��ƾɵ����ƣ����ӻ��ꡱ������ȥȥ���˲��࣬ÿ���˵����ź���
����̫�¾ɡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"zahuo",
		"south": __DIR__"mroad4",
		"northeast": __DIR__"mroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
