// searoad.c
inherit ROOM;
void create()
{
        set("short", "ƽ̨");
        set("long", @LONG
��ɽ�����ɣ�����һ��Сͤ����ʯ����������ɹۡ�һ���������ǰ����һ
������ֱ����ۡ�
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl1" : 2,
        ]) );
        set("exits", ([ 
	  	"west" : __DIR__"uproad3",
  		"eastup" : __DIR__"uproad4",
	]));
        set("outdoors", "tieflag");
	set("coor/x",80);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

/*

int valid_leave(object who,string dir)
{   
    object girl, mask;
    string gender;
    
    girl=present("sword girl",this_object());
    
    mask = present("skinmask", who);
	if (objectp(mask) && mask->query("equipped")) 
		gender = mask->query("fakegender");
	
	write ("gender is " + gender + "\n");	
    if(girl && living(girl) && userp(who) && dir == "eastup") {
		if ( (gender && gender == "����")
				|| who->query("gender")=="����")
   		{
   			message("vision",girl->name()+"˵��������λ��������������\n",this_object());
   			return notify_fail(""); 
   		}
   	}
   	return 1;
}
*/