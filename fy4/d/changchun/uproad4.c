// searoad.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ������ֱ����ۣ�Ҳ��֪�м�ǧ���ٲ㣬��ʯ��ɨ�øɸɾ������·���ʯ��
LONG
        );
        set("exits", ([ 
	  	"westdown" : __DIR__"platform",
  		"eastup" : __DIR__"moonding",
	]));
        set("outdoors", "tieflag");
	set("coor/x",90);
	set("coor/y",0);
	set("coor/z",50);
	setup();
}
int valid_leave(object who,string dir)
{   
    if(userp(who) && random(9))
   	{
//	 	who->move(this_object());
		who->ccommand("look");
	 	return notify_fail("");
   	}
   	return 1;
}