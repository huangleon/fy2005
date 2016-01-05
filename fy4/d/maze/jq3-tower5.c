// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�ƽ�����"NOR);
	set("long", @LONG
�����ǻƽ����Ķ��㣬�����濴�ƺ�����С���������У�����������ʮ�� 
�����������۵Ļƽ��⣬��û�б���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"down" :  __DIR__"jq3-tower4",
	]));
        set("item_desc", ([

	]) );
	set("objects", ([
                __DIR__"npc/jq3-shangguan" : 1,
                __DIR__"npc/jq3-chixu" : 1,
                __DIR__"npc/jq3-meihuadao" : 1,

 	]) );
	setup();
	
}


string *event1_msg=	({
	
	WHT"\n���������۰��룬§�����ɶ�������Ц�������������չ��Ƿ������ӣ�
�����������ϵ������㵽����������һ�⡣��\n"NOR,
	
	HIR"����δ�䣬ͻȻ�����ķ�Ʈ���ĸ��ˣ�ɮ�����塣 
���������飬��������Ԫ�����֮�գ��� 
�˹���ʦ�����˷磬���������˺��������С��죬�أ��ˡ���ζ���֮�� 
��۵��ɵ�֮�ϡ����� \n"NOR,
	
	HIR"һ�ѻ��ķɵ���ȼ���ŵķɵ���
	
	С��ɵ��� \n"NOR,

        HIR"\nС��ɵ��������鷢��  \n\n"NOR,

    	HIW"�����ӻ�����뷢ͻȻʧȥ����������ή�����䡣 
������۹⻬�ļ���ɲʱ���������ɱ�ȼ�ա�����  \n"NOR,
    	
    	HIW"�����Ӳҽ�һ���������£�����ȼ�յ���Ӱ���٣�һ��ҽ���û���¡� 
���ɶ�Ҳ�������֮�٣������ļ���������ȼ�ա�����

	���ɶ�ʹ���˻���ţ������š� \n"NOR,

    	HIW"���ڣ����ɶ������˼��µ��ڵ��ϣ����ˡ� \n"NOR,

});


void event1(object me, int count)
{
	object lu, meihuadao;
	object who, *inv;
	int i;
	mapping data;
	
	lu = present("chi xu", this_object());
	meihuadao = present("meihuadao",this_object());
		
	if (!lu || !meihuadao)	return;
			
	message_vision(event1_msg[count]+"\n",me);
	if(++count==sizeof(event1_msg))
	{
		destruct(lu);
		meihuadao->die();
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s��%s��Ⱥ���ڽ�Ǯ��ƽ���һ���д��ȫʤ��ǧ��������", NATURE_D->game_time(),
				me->query("name")) );
		
		// TIME to REWARD ALL
		inv = all_inventory();
		for (i = 0;i<sizeof(inv);i++)
		{
			if (!userp(inv[i]))	continue;
			who = inv[i];
			
			if (REWARD_D->check_m_success(who,"��������"))
			if (!REWARD_D->check_m_success(who,"��ս�ƽ���"))
			{
				REWARD_D->riddle_done(who, "��ս�ƽ���",500, 1);
			
				data = ([
					"name":		"�ƽ�������ս�ƽ���",
					"target":	who,
					"att_1":	"str",
					"att_1c":	1,
					"mark":		1,
				]);
			REWARD_D->imbue_att(data);
			}
		}
		
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

