// seaside.c
inherit ROOM;
void create()
{
        set("short", "�������ɿ�");
        set("long", @LONG
��������Ҭ�ָ��ʣ����¼�ľ���ף���Ȼ����Ϊ����֮������̲�����ǽ�׵�
ϸɳ��һ�Ų��ϣ������ϸɳ�ӽ�ֺ�������������������ϣ��ͺ�������޻���һ
����������������⣬һ�����꣬������ȴ���˼����ɱ����֮�¡�һ��С·����
���ۣ�����ɽ�塣�����ǳ������Ŀ������ƹݣ����潸ʯ�ܲ���������Ϊ�վ���
LONG
        );
        set("exits", ([ 
		  "north" : __DIR__"cloudinn",
          "south" : __DIR__"rock0",
          "east"  : __DIR__"uproad0",
		]));
        set("outdoors", "tieflag");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);	
/*	set("coor/x",1920);
	set("coor/y",-210);
	set("coor/z",40);*/
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
	if (!objectp(boat=find_object(__DIR__"boat")))
		boat=load_object(__DIR__"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up")|| !living(oob))
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
	boat->set("exits/up",__DIR__"island");
	set("exits/down",__DIR__"boat");
	call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",this_object()); 
	boat->set_temp("mark/dest","mainland");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",boat);
	boat->boat_run(0);
}
