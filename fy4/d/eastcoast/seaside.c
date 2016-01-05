// seaside.c
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
ת��һ���䣬����ǰ��Ȼһ���ޱ��޼ʵĴ󺣾�����ǰ�ˡ�������棬һϴ
�����ÿ͵�һ·�Ͷ١��������������е���ζ������΢΢���Ų��ˡ������ĺ�ˮ��
��ӿ����׵��˻�������Ʈ������ı���ãã�Ĵ���û��һ�㷫Ӱ����ĿԶ����
���콻�紦����һƬ���ֲ��������Ǻ����������졣
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"searoad1",
		"south" : __DIR__"seaside2",

]));
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void pipe_notify()
{
        object ob;

        message("vision","һ������������԰��ߣ���������ؼ�ľ��ţ����ﵽԶ����\n" , this_object() );
		call_out("boat_come",5);
}

void boat_come()
{
	object boat;
	object woman;
	object *inv;
	object who, oob;
	int i;
	
	if (query("exits/down")) return;
	if (!objectp(boat=find_object(AREA_CHANGCHUN"boat")))
		boat=load_object(AREA_CHANGCHUN"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up") || !living(oob))
	{              
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
	}
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
		}
	message("vision","���˰��Σ�һ���洬�����е���������׿����һ���׷��ԲԵ��ϸ��ˣ����ҡ�֡�\n",this_object());
	message("vision","������˵�������ϴ��ɣ���\n",this_object());
	boat->set("exits/up",__DIR__"seaside");
	set("exits/down",AREA_CHANGCHUN"boat");
	call_out("boat_leave",10,boat);
}


void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",this_object()); 
	boat->set_temp("mark/dest","island");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",boat);
	boat->boat_run(0);
}
