inherit ROOM;
void create()
{
        set("short", "�Ƕ�С·");
        set("long", @LONG
���߾��Ǹߴ�ķ��Ƴǣ�һ�������Ĵ�����������಻����Ⱥɽ��һֱͨ��
���ߡ���·���������������ַǷ�������Щ������Ů��������࣬��ȥΪ���º��
ս�����˼���ȥ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
	  "north":	__DIR__"fyeast",
	  "southwest": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
	set("coor/x",320);
	set("coor/y",-80);
	set("coor/z",0);
	setup();     

}

