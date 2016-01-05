// Room: darklane1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
С����խ�ְ���һ������ʪ����ķ��ƹ���ʱ��ʱ�ޣ��㲻�����˸���ս��
Ѫ��֮�������ڿ���֮�У�һ��Ī���Ŀֲ���ǿ�ҵĿֲ������ʰ�ѹס�������
ͷ��Ѫ����ص�Ѫ��ʬ������ȱ��ʬ������
LONG);

	set("type","street");
	set("exits",([
		"south":__DIR__"stoneroad2",
		"north":__DIR__"darklane2",
	]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);


	setup();
}

void init()
{
        add_action("do_look","look");

}

int do_look(string arg)
{
    	object corpse;
    
    	if (!arg) return "cmds/std/look"->main(this_player(),"");
    	else 
    		if (arg != "ʬ��"&&arg!="corpses") return 0;
    	
    	write("�㷢�ֵ������ż���ʬ�壬�������˻�����һ��ʱ����\n");
    	corpse=present("bloody corpse",this_object());
     	
     	if( !objectp(corpse)) 
     	{
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    		corpse = new(__DIR__"obj/corpse");
    		corpse->set("no_get",1);
    		corpse->move(this_object());
    	}
    	if(!this_player()->query_temp("libie/���_����ʬ��"))
    	this_player()->set_temp("libie/���_����ʬ��",1);
    	return 1;
}
