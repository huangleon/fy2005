
inherit ROOM;

void create()
{
	set("short", "��̶��");
	set("long", @LONG
��ˮ��ͷ��һ�����ٲ����ڰٳ����·���ֱ�£���������״�����裬������
��̶�١���̶�б�ˮ�������峺���ס�ɽ����󣬺�ӿ��ע�����ڽ�Х������ϡϡ
�����վ�ż������ˣ��е��������еĴ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"grassland2",
  		"south" : __DIR__"lake1",
	]));
        set("objects", ([ /* sizeof() == 2 */
  		__DIR__"npc/reg_taoist" : 2,
  		__DIR__"npc/shan" : 1,
		
	]));
        set("resource/water",1);
        set("liquid", (["container":"��",
        				"name": "��̶��ˮ",	
        				
        				]));
	set("outdoors", "taoguan");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


