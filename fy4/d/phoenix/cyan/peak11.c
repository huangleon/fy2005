// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "ӳ������");
    set("long", @LONG
��ɽ�������������һ�ο�����ˮ����ϲɲʱ��������ͷ��������������
һ�����������ˮ�����ֱ�����Ľ�֮���븹�С�һ����䣬ֻ������ӯӯ��
ˮͻ�����˲������������������ģ�ֻ����ˮ�����ã���ӳ�ŵ�ٲȻ�Ƿ�
�Ƴ��ڹ⾰��
LONG
NOR
        );
	set("objects", ([


	]));
	set("item_desc", ([
	"��ˮ":"����Խ���ӳ��������ħ�����ۿ�����Ҫ֪��������(scry)��\n",
	"��":"����Խ���ӳ��������ħ�����ۿ�����Ҫ֪��������(scry)��\n",
	"lake":"����Խ���ӳ��������ħ�����ۿ�����Ҫ֪��������(scry)��\n"

	]) );
	set("exits",([
  		"northdown" : "peak7",
  		"westdown" : "peakx",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init() {

object ob;
object me = this_player();
	::init();



	if (REWARD_D->riddle_check(me,"�ع�����") == 1) 
	{
		ob=new(__DIR__"npc/dizi");
		ob->set("name","����");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("name","����");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("name","����");
		ob->move(this_object());
		ob=new(__DIR__"npc/dizi");
		ob->set("nickname",HIR"Ѫ����ħ"NOR);
		ob->set("title","����ħ�� "MAG"��ħ̳��"NOR);
		ob->set("name","�³���");
		ob->set("id","master mu");
		ob->move(this_object());

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);


	}


	add_action("do_scry","scry");
}



void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$n�������������ⲽ����$N����������΢¶ϲɫ��
$n�����ѹ⣬�㵽����ȥ�ˣ�Ϊʦ���ǷԸ�����ɽ֮�󣬾������˴����ô��\n",

"$n˵����Ҳ�գ�Ҳ�գ����˾ͺá�
$n˵������ʨ��������ʱ��ǰ�ɸ봫�������б䣬"WHT"���ǵ���"CYN"�������ߡ�",

"$n����Ϊʦ������ٸϻأ��˴�"WHT"��Ѫƽ��"CYN"����ıɨ������֮�£��㽻����һ�����֡�\n",
"$nתͷ�Ը��ڵ��ӵ���������С��β���ڸ�̳��������ս���ٳ�����ǡ�
$n�ٺ���Ц����������Щ��ԭ���ţ��ָõ�������ʲôʮ����֮ͽ�ˡ�\n",

"$n��$Nһ�����ٻ���ɢ��˵����������ԭ������������˼�������������ѹ����Ҫǧ��С�ģ���Ī�д�",
"$n����$N�ļ���������ת˲�仯��һ��������ʧ��ɽ��֮�䡣
�ڵ�����$N����һ������ɢ��ȥ��\n",
});
	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];


	message_vision(CYN+msg+"\n"NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{

	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"�뿪"CYN+"ӳ������"+WHT""NOR);
	me->set("quest/location", "ӳ������");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"�ع�����",2);
		destruct(target);
		target=new("/d/phoenix/npc/obj/cyan_drug");
		target->move(me);
		me->set_temp("disable_inputs",0);
		if (present("dizi"))
			destruct(present("dizi"));
		if (present("dizi"))
			destruct(present("dizi"));
		if (present("dizi"))
			destruct(present("dizi"));
		return;
	}
	return;
}


// inventory messages.
string inventory_look(object obj, int flag) {
    string str, desc;
    object me, left, right;

    str = obj->short();
    if(obj->query("equipped")) {
        if(!desc = obj->query("armor_worn")) {
            if(!desc=obj->query("weapon_wielded")) {
                desc = "��";
            } else {
                me = environment(obj);
                left = me->query_temp("left_hand");
                right = me->query_temp("right_hand");
                if(obj == left && obj == right) {
                    desc = "˫��" + desc + "��";
                } else if(obj == right) {
                    desc = "����" + desc + "��";
                } else {
                    desc = "����" + desc + "��";
                }
            }
        }
        str = desc + str;
    } else if(!flag) {
        str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
                "����" : "  ") + str;
    } else {
        return 0;
    }
    
    return str;
}

int do_scry(string arg)
{
	object me = this_player();
	object obj;

    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;

	if (!arg)
		return notify_fail("����Ѱ��ʲô��\n");

	if (me->query_temp("timer/big_cmd")+2 > time())
		return notify_fail("ӳ�������е�ˮ����û�г���ƽ�����ٵ�һ�Ȱɡ�\n");
	else
		me->set_temp("timer/big_cmd",time());

	me->add("sen",-30);

	obj = find_living(arg);
	if (!obj)
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	if (!environment(obj))
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	if (userp(obj))
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	 if (obj->query("race")=="Ԫ��")
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");


	message_vision("ӳ������ˮ��������ã�����������ƽ����\n",me);
	message_vision("���е�ӳ����"+obj->name()+"����Ӱ��\n",me);

	str = obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

    if((string)obj->query("race")=="����" && intp(obj->query("age")))
    {
        if(userp(obj))
		{
            str +=  sprintf("%s��������%s�����%s�ˡ�\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10), obj->query("national"));
		    } else 
			{
            str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10));
			  }
    }

    // current kee status.
    if(obj->query("max_kee")) {
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
                / (int)obj->query("max_kee")) + "\n";
    }
    
    // inventory message.
    if(obj->query("race") == "����") {
        str += pro + (obj->is_naked() ? "�������塣\n" : "");
    }
    inv = all_inventory(obj);
    if(sizeof(inv)) {
        inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
        inv -= ({ 0 });
        if(sizeof(inv)) {
            str += sprintf("%s\n", implode(inv, "\n  "));
        }
    }
    // tatoo print
    if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";

    
    // send out message
    message("vision", str + "\n", me);
	return 1;
}




int	valid_leave(object who, string dir)
{
	object me;
	me = who;
		if (REWARD_D->riddle_check(me,"�ع�����") == 3) 
		{
			return notify_fail("���ȥ·����ڣ��ס�ˣ�\n");
		}

		if (REWARD_D->riddle_check(me,"�ع�����") == 2) 
		{
			REWARD_D->riddle_set(me,"�ع�����",3);
			who=new(__DIR__"npc/j1");
			who->move(this_object());
			message_vision(HIR"һ����Ӱͻ�Ժ��ߵĴ����Ϸ��Ӷ��£���ס$N��ȥ·��\n"NOR,me);
			message_vision(HIR"$N����������̡�Ӧ�������嵴��ԭ���������ţ�����ԭ�£�
$N�����ߡ���ͷ���¸ߣ��㣬���еģ������ɣ�\n\n"NOR,who);	// not typo.
			who->kill_ob(me);
			me->kill_ob(who);
			return notify_fail("\n");
		}

	return ::valid_leave(who,dir);
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


