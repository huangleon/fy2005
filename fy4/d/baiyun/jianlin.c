//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
object generate_it(int exp,object mail,object me);
object find_env(object ob);

void create()
{
    set("short", "����");
    set("long", @LONG
�˴�����Ϊ�֣�ȴֻ��һ��˶���ޱȵĿտ�ʯ�ң����滷ɽ����ʯ���汻��ĥ��
ʮ�ֹ⻬�����ǰ��Ƴǵ��ӳ�Ϧ����ϰ��֮�������Ƴ�����Ϊһ�������ѣ���������
֮�ˣ��������µ���ϰ��Ҫ���ϣ���˰��Ƴǵ��ӽԿ̿�������������˿���Ͷ裬
����ʯ���ϲ����˸�ʽ�������۵ĳ��������Ƴ�����ν�����ڽ�ʿ����νʮָ���ġ�
������۵ķϽ���ҲҪ���ƴ��á��˴���Ϊ���֣�ʵΪ��ڣ��
LONG
    );
    set("exits",
      ([
	"northwest" : __DIR__"jintaoting",
	"southup" : __DIR__"guajianbei",
	"westdown" : __DIR__"qianlonghu",
      ]));

    set("item_desc", ([
    	"ʯ��": "ʯ���ϲ����˸�ʽ�����ĶϽ���broken-sword������������ŰΣ�pull��������\n",
    	"��ʯ": "ʯ���ϲ����˸�ʽ�����ĶϽ���broken-sword������������ŰΣ�pull��������\n",
    	"rock": "ʯ���ϲ����˸�ʽ�����ĶϽ���broken-sword������������ŰΣ�pull��������\n",
    	
    	]) );


    set("objects",
      ([
	__DIR__"npc/jiannu" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-60);
    set("coor/z",10);
    setup();
}

void init()
{
    add_action("do_pull","pull");
}

int do_pull(string arg)
{
    object blood;
    object me = this_player();
    if(!arg || (arg != "broken-sword" && arg != "sword")) return 0;
    	message_vision("$N�þ�ȫ������������һ������\n",me);
      	
    if (!me->query_temp("annie/pull_sword") || random(7) || query("sword"))
    {
		message_vision("$N�����������������۵ÿ�����Ѫ������\n",me);
		me->receive_damage("kee",50);
		blood= new("/d/wanmei/obj/blood");
		blood->move(this_object());
		me->set_temp("last_damage_from","�ڰ��ƽ����������������ˡ�\n");
		me->set_temp("annie/pull_sword",1);
		return 1;
    }
    message_vision("˭֪���Ͻ�ֻ�����ɲ��ڱ��ϣ�$N�������ͣ��ҽ�һ����
ִ�ŶϽ�������󵹷��˳�ȥ������һ�����ڵ��ϣ�������һ˿��Ѫ��

�Ͻ����ַɳ�����Х���д����ƶˣ�Ҳ��֪���䵽����ȥ�ˡ�\n",me);
    set("sword",1);	
    blood=new(__DIR__"obj/8sword");
    generate_it (8000000,blood,me);
    me->receive_damage("kee",300);
    me->set_temp("last_damage_from","�ڰ��ƽ����������������ˡ�\n");
    return 1;
}


object generate_it(int exp,object mail, object me)
{
	object room,*ulist, place, ob;
	int i,m,flag,fdd,num;
	string file, where;
	ulist=objects();
	m=sizeof(ulist);
	flag=1;

	exp = 8000000;
	while (flag)
	{
		i=random(m);

//		write ("attemp ------fdd = " + fdd + "\n");
//		write (sprintf("it is %O\n",ulist[i]));
		
		if (!ulist[i])
			continue;
		if (!environment(ulist[i]) && !ulist[i]->query("short"))	// not a room: something in the planar void
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/login#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// ��֪����ʲô����
			continue;
		
		if (!ulist[i]->query("short") && fdd < 3)		// ���������������������exp��ѭ��, and teach ppl hiding places.
		{
			fdd++;
			continue;
		}

		room=ulist[i];
		
		// ������ player����Ҳ������ playerЯ����������		
		if (userp(room))	continue;		
		if (objectp(environment(room)) && userp(environment(room)))	
			continue;						
		
		// �����������Ӧ�ô�����ĳһ���������棬ȥ����Щ�޻�����NPC					
		ob = find_env(room);				
		if (!ob)	continue;
			
		if (ob->query("no_fight"))			continue;
		if (ob->query("no_death_penalty"))	continue;
		if (ob->query("no_fly"))			continue;	
		if (ob->query("perma_exist"))		continue;
		if (ob->query("no_lu_letter")) 		continue;	// Some rooms are tricky, can't get
					
		where = file_name(ob);
    	if (   where[0..7]=="/d/death"
    		|| where[0..4]=="/d/fy"			// including fy,fycycle,fywall
    		|| where[0..7]=="/d/eren2"
			|| where[0..6]=="/d/maze"
			|| where[0..5]=="/d/wiz"
			|| where[0..9]=="/d/welcome"
			|| where[0..9]=="/d/phoenix"
			|| where[0..8]=="/d/bashan"
			|| where[0..8]=="/d/zhaoze"
			|| where[0..9]=="/d/taoyuan"
			|| where[0..9]=="/d/shanliu"
			|| where[0..2]=="/p/"
			|| where[0..4]=="/obj"
			)
			continue;
								
		// ������ط���һ��NPCʱ
		if (room->query("combat_exp"))
		{
			if (room->query("NO_KILL"))					continue;
			if (room->query("vendetta_mark/authority"))	continue;
			if (room->query("possessed"))				continue;
			if (room->query("no_lu_letter"))			continue;
			if (room->query("combat_exp")> 10050000)	continue;	// capped around 10M				
			if (room->query("combat_exp") > exp/10*12 && fdd < 20)
			{
				fdd++;
				continue;
			}

			if (room->query("combat_exp") < exp/10*8 && fdd < 10)
			{
				fdd++;
				continue;
			}
		}
	
		if (room->query("id") == "skeleton" || room->query("id") == "corpse")
			continue;
			
		if (mail->move(room))
		{
			CHANNEL_D->do_sys_channel("sys","move to " + file_name(room) + "\n");
			CHANNEL_D->do_sys_channel("info","�ݴ�"+me->name()+"�ڰ��Ƶ���һ�ѹŽ���ȴ�ֵö���ʧ��\n");
//			write("move to "+ file_name(room)+"\n");	
			flag=0;
		}
	}
	return mail;

}

object find_env(object ob)
{
	while(ob)
	{
		if(ob->query("coor")) return ob;
		else 
			ob=environment(ob);	
	}
	return ob;
}

int reset(){
	if (!random(20))	set("sword",0);
	::reset();
}

/*

	       (\~~~/)            
	       ( ����)        

	       (_____)~��      

��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
