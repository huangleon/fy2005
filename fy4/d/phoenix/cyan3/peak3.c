// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";


string lic();

void create()
{
	set("short", "�t��̨��");
    set("long", @LONG
��һ���䱸ɭ�ϣ������о����������������֮�����������שʯ����
�����£���������������滨��ǹ��������ǽ�������ϣ���ǽ������������
�ڣ�սʱ�ڶ���ϼȿ��Գ���ǯ��������ϼɽ�������ָ�Ӳt��̨�ϵ������
�����Է���֮��Զ�䣬�����ƳǶ�ֱ�������ȵ���ʮ���·����������
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path6",
	]) );

	set("stat",1);

	set("area","cyan3");
	set("item_desc", ([

	"eastdown": (: lic :),

	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}


string lic()
{
	string str;
	object m;
	int i = time();

	if (!query("m"))
		return 0;
	if (query("stat") == 1)
		str="\n��������Ƹ�����ɽ������һ��ļž�����ʱ���о�������Զ������ʾ��һ����籩������١�\n";

	if (query("stat") == 2 && !random(5))
	{
		str="\n��żȻ������Ļ�ĵ�����ֻ��ɽ����������ѹѹ��һƬ�������ˣ�����ˮһ����ɽ��ӿ����\n";
		i=query("apres_vague") - i;
		str += HIW"��һ����������"+i+"��֮�󵽴�t��̨��\n"NOR;

	}
	else if (query("stat") == 2 )
		str="\n��������Ƹ�����Զ����ɽ��ڳ���ѹ�£������ɽ�ż���ȥ��ɨ��ֻ����һ����֦��Ҷ�۵�������\n";

	if (query("stat") == 3)
		str="\n�������������Լ��������ˮ��������ɽ����Ѫ���㼯��������СϪ��ɽ����ȥ������\n";

	return str;
}






void init()
{
	object ob;
	object a,b,c, s1, s2, s3,m;
	object me = this_player();
	object here = this_object();
	::init();

	if (!userp(me))
		return;

	if (REWARD_D->riddle_check(me,"���Ļ���") ==4) 
	{
		
		s1 = new(__DIR__"npc/soldier");
		s1->move(here);
		s1->init_me(me,"garrison",1);
		s1->set("name","�ؾ���");
		s2 = new(__DIR__"npc/soldier");
		s2->move(here);
		s2->init_me(me,"garrison",1);
		s2->set("name","�ؾ���");
		s3 = new(__DIR__"npc/soldier2");
		s3->move(here);
		s3->init_me(me,"garrison",2);

		s1=new(__DIR__"npc/wd");
		s1->move(here);
		s1->init_me(me,"wd",2);
		s1=new(__DIR__"npc/wd");
		s1->move(here);
		s1->init_me(me,"wd",2);


		m = new(__DIR__"npc/wall");
		m->move(here);
		m->set("max_kee",me->query("max_kee")*10);
		m->set("eff_kee",me->query("max_kee")*10);
		m->set("kee",me->query("max_kee")*10);
		set("m",m);

		call_out("a",1,me,m);
	}
	
	return;
}

int do_start(object me,object ob,object m)
{
	object here = this_object();

	int i,j,k;
	string r,s,t;

	set("owner_ob",me);	// Don't use "owner", conflict with annie_room
	set("ownerr",me->query("name"));

tell_room(this_object(),CYN"
��ϼ�ر�������������Զ����������һ�ۣ�û�뵽�������ܳÿ��������
������Ҫ�����ϲt��̨ת��������Ҫ��������������ס���������ֲ���ѽ��

�ؾ���˵�����ٳ����ģ����찳����ƴ��������Ҫ��Ҳ��������Щ������̤��ԭ��

�ؾ��������ش��˴��ֵ����Һ����䵱�ļ�λ����ǰ������������ɾͿ��۵��ˣ�\n\n"NOR);

	set("commencer",time());
	set("apres_vague",time() + 30);
	
	call_out("attacks",30,me,m,ob);
	call_out("delay",40,m,me,0);
	return 1;

}


void a(object me,object m)
{
	object ob = present("li qingzhuo",this_object());
	if (!ob)
	{
		call_out("a",1,me,m);
		return;
	}
	do_start(me,ob,m);
	me->set("quest/short", "������ϼɽ�t��̨"NOR);
	me->set("quest/duration",1800);
	me->set("quest_time",time());
	message_vision(HIY"�������ı��ˣ�\n"NOR,me);

}

void failed()
{
	if (query("owner_ob"))
		query("owner_ob")->die();
}

void delay(object m, object me, int i)
{
	if (!m)
	{
		tell_room(this_object(),HIR"\n�����Ѫ�����죬һ������ڻ��������������ϣ�����\n"HIW"\n������ϼ�ذ���ʧ�أ������º����˺�������ֱ�룬������ɱ����ԭ���һʱ��\n������Ұ�����������ʮ���������ʧ����������Ǩ������"HIY"\n\n���ź�������ʧ���ˡ�\n\n"NOR);
		failed();
		return;
	}

	if (i<9)
	{
		i++;
		set("wave",i);
		call_out("delay",40+random(40),m,me,i);
		tell_room(this_object(),HIC"\n�t��̨�����˺������ٶ�����������Ѿ��Ѵ���ת��"+CHINESE_D->chinese_number(i)+"���ˣ�\n\n"NOR);
		return;
	}

	tell_room(this_object(),HIC"\n�t��̨�����˴�ȵ������ˣ����ˣ�\n"HIR"ֻ����һ����Ȼ���죬�����t��̨�͵�һ�������ڵ��߻ҳ����������䡣���Զ��\n̽ͷ����������һ����������ɽ��ֱ�ܶ��£�����֮�����ɽ�����������������һ\n�����죬һ������Ю���������Բt��̨�����£�����һ������ֱ��ɽ�⣬������\n��̨���Ļ�����Ц��\n\n"NOR);
	tell_object(me,WHT" ңԶ��ɽ�䴫��Ʈ�첻���ĵ���������������Լ������������ɤ����
����ǧ��ޣ��޼������ġ�ɽ�²�֪�����£�ˮ�������ǰ��������

"CYN"�㿿�ڲt��̨�ڵ������ϣ�����̨��Ĵ�����������һ˿����ĵ���������������
������һ���ޱߵľ���Ϯ����£�����\n"NOR);
	tell_object(me,"");
	me->leftnow();
	return;

}

void attacks(object me, object m,object ob)
{

	object here = this_object();
	object a,b,c, s1, s2, s3;
	int i,j,k;
	string r,s,t;

	if (!m)
	{
		tell_room(this_object(),HIR"\n�����Ѫ�����죬һ������ڻ��������������ϣ�����\n"HIW"\n������ϼ�ذ���ʧ�أ������º����˺�������ֱ�룬������ɱ����ԭ���һʱ��\n������Ұ�����������ʮ���������ʧ����������Ǩ������"HIY"\n\n���ź�������ʧ���ˡ�\n\n"NOR);
		failed();
		return;
	}

	set("stat",2);

	i = random(100);
	if (i<=2)
		j=5;
	else if (i<=7)
		j=4;
	else if (i<=47)
		j=3;
	else j=2;
//	tell_room(this_object(),"i is:"+i+"\n");

	message_vision(WHT"\nһ�����׶���ը�죬�t��̨���͵�һ������"+chinese_number(j)+"����Ӱ�������Ծ����������\n"NOR,me);

//  Let's avoid the super flooding here :)	
	if (b=present("fengyun garrison"))
		b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");
	if (b=present("li qingzhuo"))
		b->ccommand("emote ���������");

	for (i=0; i<j; i++)
	{
		a = new(__DIR__"npc/attacker");
		a->move(here);
		a->init_me(me,"attacker",i+2);	
		a->ccommand("kill launch mechanism");
		a->kill_ob(m);
		a->add_hate(m,2000+random(2000));

		if (b=present("fengyun garrison"))
		{
//			b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}
		if (b=present("fengyun garrison 2"))
		{
//			b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));

		}
		if (b=present("fengyun garrison 3"))
		{
//			b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}

		if (b=present("dizi"))
		{
//			b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}

		if (b=present("dizi 2"))
		{
//			b->ccommand("emote ��ȵ��������ݵò�Ᵽ�");	
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}

		if (b=present("li qingzhuo"))
		{
//			b->ccommand("emote ���������");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,-99999);
		}
	}

	k=40+random(20);
	k-=query("wave");
	set("apres_vague",time() + k);
	call_out("attacks",k,me,m);
	return;

}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	return notify_fail("���ڿɲ��ǵ����й��ʱ�򣮣���\n");
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


