inherit ROOM;

void create()
{
	set("short", "��");

	set("long", @LONG
����ɽׯ�Ĳ񷿺��񲢲��ǶѲ�ģ����ǹ��˵ġ�����ץס��ǿ�������Ὣ��
���ڲ��������֩�룬�������й�ʺè���ù����룬����ʣ�µ�[33múм[32m��
����ʲ�ᶼ�У�����û�в�������û�С� 
LONG
	);

	set("type","house");
	set("indoors", "fugui");
	set("exits",([
		"south":__DIR__"grass4",
	]) );
	set("objects" , ([
		__DIR__"npc/suan":1,
	]));
    	set("item_desc", ([
        	"úм": "���ﵽ������úм�����ƺ����Դ�ɨһ�£�clean����\n",
        	"breeze": "���ﵽ������úм�����ƺ����Դ�ɨһ�£�clean����\n",
        ]) );

	set("coor/x",10);
	set("coor/y",250);
	set("coor/z",80);
	setup();
	
}

void init()
{
        add_action ("do_dight", "clean");
}

int do_dight()
{		
	object mh,bo;
	int eff_kee;
        if (!present("saoba",this_player())) 
        	return notify_fail("������û��ɨ�ѣ���ô��ɨ��\n");
        eff_kee = this_player()->query("kee");
        if (eff_kee < (int)this_player()->query("max_kee")/10)
        {
        	return notify_fail("��̫���ˣ���ô��ɨ��\n");
        }
	this_player()->receive_damage("kee",(int)this_player()->query("max_kee")/10);
	if (this_object()->query("dighted"))
	{	message_vision("$N����ɨ�Ѷ�����˵��ɨ������\n��ʱ������������Ļҳ�����ֱǺ��͸��������\n������һ������������ɾ���Щ��\n\n", this_player() );
        	return 1;
        }
	else if (random(5)) 
	{
		message_vision("$N����ɨ�Ѷ�����˵��ɨ������\n��ʱ������������Ļҳ�����ֱǺ��͸��������\n������һ������������ɾ���Щ��\n\n", this_player());
        	return 1;
	}
	else 
	{
		message_vision("$N����ɨ����������ɨ�ţ�ͻȻ��һ���ڰ��Ľ�����ƺ�������һ��Сľ���ӡ�\n", this_player());
		this_object()->set("dighted",1);
		mh=new(__DIR__"obj/muhe");
		bo=new(BOOKS"spear_50");
		bo->move(mh);
		mh->move(this_player());
		return 1;
	}
	return 0;
}

void reset(){
        ::reset();
      
	if(this_object()->query("dighted")){
                this_object()->delete("dighted");
        }
        return;
}         