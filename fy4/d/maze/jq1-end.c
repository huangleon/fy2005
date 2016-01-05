// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
һ����������Ĵ󴲷������У������׵Ĺ�ɴ��ͬ��֬һ�����϶��£�����
�ܵ��ϣ�������ɴ֮�䣬�ƺ���һ�Ծ�������Ӱ�ڰ�ɴ�����ط�������ɫ�ޱߣ�Ũ
���޷����������ǵ�Ů�ӵ����̽�����ʱ����������� 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq1-exit",

	]));
        set("objects", ([
                __DIR__"npc/jq1-lufengxian": 1,
                __DIR__"npc/jq1-meihuadao": 1,
        ]) );

        set("item_desc", ([
	]) );
	setup();
	
}


string *event1_msg=	({
	
	WHT"\n����Ӱ��֮�䣬�ǶԽ���������һ�����Ӱէ�ط��˿�����\n"NOR,
	
	WHT"���٣�������˲��񣿵������н��������ȵĺ��£��� \n"NOR,
	
	WHT"÷������ɢ��б����ɴ�У�����Ц�������ȣ���˵������������˫��
ū�Һ�����ϸ����� \n"NOR,

        WHT"\nɴӰ����������߹�֮��������� \n\n"NOR,

    	HIR"�����Ƚ�ü��������Ȼ��Ц���������ɡ� \n"NOR,
    	
});


void event1(object me, int count)
{
	object lu, meihuadao;
	
	lu = present("lu fengxian", this_object());
	meihuadao = present("meihuadao",this_object());
	
	if (!lu || !meihuadao)	return;
	if (environment(me)!=this_object()) 	return;
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		lu->kill_ob(me);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

void init()
{       
        add_action("do_answer","answer");
    
}

string *event2_msg=	({
	
	HIR"\n������ͻȻ˻������һ����Ϊʲô��Ϊʲô��ĳ������ʹ����һ�ˣ� \n"NOR,
	
	HIR"�����Ȼع������Ŵ��ϵ�÷�����������ص����㣬�㣿Ϊʲô��������ң�
�ѵ�����Ϊ�Ҳ����Ϲٽ��ô�� \n"NOR,
	
	HIR"��������Ҫ�������������÷����������һ����������ѵ�һ�����ڵ��ϡ� \n"NOR,

	HIR"\n�������޾����˵Ŀ�Цһ�����ɶ���������������㡣���� �� 
һ��δ�գ�������һ�ַ������������ڰ�ɴ��Ѫ֮�С� \n"NOR,

    	GRN"\n÷���������֫�������������ȵ�ʬ��б���ڴ��ϣ���Ц������Щ�����ˣ�������ϧ��\n"NOR,
    	GRN"\n÷��������̧��ͷ��������Ͼ�Ľ�������Ť������׵����ż��ٵ������ֻ�ǿ����㡣 \n"NOR,
    	GRN"\n÷����ֻ��΢Ц�ÿ����㣬����ȷ������˵���� \n"NOR,
    	GRN"\n�����۾���˵��������΢Ц��˵�����������֣��������ţ������ȡ��������ϵ�ÿ��
ÿ�ֶ���˵����\n"NOR,
    	
});


void event2(object me, int count)
{
	object lu, meihuadao, spear,*inv;
	int n;
	
	lu = present("lu fengxian", this_object());
	meihuadao = present("meihuadao",this_object());
	
	if (!meihuadao)	return;
	if (environment(me)!=this_object()) 	return;
		
	tell_object(me,event2_msg[count]+"\n");
	if (count == 3) {
		lu->set("die",1);
		if (spear = present("spear",lu)) 
			spear->move(this_object());
		else { inv = all_inventory(this_object());
		 	n = sizeof(inv);
		 	while (n--) {
		 		if (inv[n]->query("lu_spear"))
		 			spear = inv[n];
		 	}
		}
		if (!spear) {	
			spear = new (__DIR__"npc/obj/silver_spear");
			if (spear) spear->move(this_object());
		}
		spear->set("name","մ����Ѫ�����");	
		lu->die();
	}
	if(++count==sizeof(event2_msg))
	{
		if (me->query("gender")=="����") {
			tell_object(me, HIG"
�㲻����Գ����ֻҪ�����ˣ���Ȼ������˵�ġ�����������Ը�⣨answer accept��
���Ǿܾ���answer reject����\n"NOR);
			me->set_temp("maze/jq1_answer",1);
		} else 	{
			tell_object(me,HIG"
��Ȼ����ΪŮ�ӣ���������˽��ĵĿ��˶�������Ҳ���г����һ���������¶��ϣ�
ӿ��ȫ���Ǵ�Ӧ����answer accept�����Ǿܾ���answer reject���أ� \n"NOR);
			me->set_temp("maze/jq1_answer",2);
		}
		call_out("do_escape", 40, me, meihuadao);
		return;
	}
	else call_out("event2",1,me,count);
		
	return ;
}

int 	do_escape( object me, object meihuadao)	{
	message_vision("\n\n÷��������һЦ������Ȼ�������Ѷϣ������������������ū�Ұɡ��� \n", me);
	tell_object(me, "�㱻һ���߳������⡣\n");
	me->stop_busy();
	me->move(__DIR__"jq1-exit");
	return 1;
}

int 	do_answer(string arg) {
	object me;
	object room, spear, meihuadao;
	me = this_player();
	if (!me->query_temp("maze/jq1_answer")) return 0;
	if (me->query_temp("maze/jq1_answer") == 1) {
		remove_call_out("do_escape");
		me->delete_temp("maze/jq1_answer");
		if (arg == "accept") {
			tell_object(me, HIY" 
����Ŀ����÷����ѩ�׵����ţ�˫�ȡ��������л�δ�����������ѽ��Ͱ͵�����Ը�⡣ 
÷���������̡�һ��������Ļ��һ˿����Ϯ���������ѹ����ڽ�׵�ɴ��֮�С� 
������ο�ʼ�ˡ������� \n\n"NOR);
			me->set("maze/��Ǯһ��",1);
			me->ccommand("drop all");
			me->unconcious();
			room = find_object(AREA_FY"swind3");
			if (!room) room = load_object(AREA_FY"swind3");
			me ->move(room);
			me->stop_busy();
			return 1;
		}
		if (arg == "reject") {
			message_vision(HIW"
$N��ס��������ֹˮ���������÷��������������£������������� 
����δ�䣬÷��������Ц����������Ŀ��ת������������Ȼ��ˣ�ˡū�ҾͲ������ˡ� 
÷������������һ����ͷɴ������ͻȻһ����÷����˲����ʧ����Ӱ���١�\n\n"NOR, me);
			me->stop_busy();
			if (meihuadao = present("meihuadao",this_object()))
				destruct(meihuadao);
			return 1;
		}
	}
	if (me->query_temp("maze/jq1_answer") == 2) {
		remove_call_out("do_escape");
		me->delete_temp("maze/jq1_answer");
		if (arg == "accept") {
			tell_object(me, HIY" 
�����һƬ�հף�������Ų����������÷�������С����� 
÷��������һЦ�������ã��ý�������ô��������Ů�ˡ����� 
�����ź������һ����������֫���ؿڡ����� 
������ο�ʼ�ˡ�������  \n\n"NOR);
			me->set("maze/��Ǯһ��",1);
			me->ccommand("drop all");
			me->unconcious();
			room = find_object(AREA_QIANJIN"wting");
			if (!room) room = load_object(AREA_QIANJIN"wting");
			me ->move(room);
			me->stop_busy();
			return 1;
		}
		if (arg == "reject") {
			message_vision(HIW"
$N����һ���������̿ɶ���û�����Ȥ�������ɡ����� 
����δ�䣬÷��������Ц����������Ŀ��ת������������Ȼ��ˣ�ˡū�ҾͲ������ˡ� 
÷������������һ����ͷɴ������ͻȻһ����÷����˲����ʧ����Ӱ���١� \n\n"NOR, me);
			me->stop_busy();
			if (meihuadao = present("meihuadao",this_object()))
				destruct(meihuadao);
			return 1;
		}
	} 

	return 0;
}
		
   			