inherit ROOM;
void create()
{
        set("short", "̫ƽ��");
        set("long", @LONG
̫ƽ��ԭ��ֻ�Ǹ��ټҵ���վ���������˶��ˣ����𽥿����˼������̡�����
ǰ��ɽ����Ȼ������һ������ĸ����������������һ��ׯ԰�����ϵ����˶��ˣ�
��Ȼ�������������ֵĵط������������¥Զ��������������ʹ���������Բ��Ǹ�
�ܷ����������ܹ���ס�Ű�ʮ�����˼ҡ�
LONG
        );
        set("exits", ([ 
		"northeast" : AREA_ZANGBEI"kunlun1",
		"east": __DIR__"yizhan",
		"southwest": __DIR__"mroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}
