inherit ITEM;
#include <ansi.h>
void create()
{
    string *order=({"ʯ��","�Ϲٽ��","������",HIY"�������"NOR,
    	"������","�Ϲ���","�δ�","����","ѩ���","������","�˹���ʦ","����",
    	"���","����","���촸","������","ʯ����","��ˮ����",HIG"�����"NOR,
    	"��ս","��һ��","������","��÷��ʦ","����","����ü","����","�����",
    	"������","���ʮ����","¬����"});
	string letters;
	int i;
	set_name("��̴ľ��", ({ "purple box", "box" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "wood");
		set("no_give",1);
		set("no_drop",1);
		set("no_split",1);
		set("no_burn",1);
		set("long","����һ����̴ľ�У�����ڷ���һ������������(Send)\n");
		set("annie/real_by_box",1);
		for (i=0; i<6; i++)
			order -= ({ order[random(sizeof(order))] });
		order += ({ "�ϵ�����","½С��" });

		set("letters",order);
	}
}

string long()
{ 
	int i;
	string msg;
	string *letters;
	letters=query("letters");
	msg=query("long");
	if (!sizeof(letters)) return msg;
	msg+="�����У�\n";
	for( i=0;i<sizeof(letters);i++)
		msg+="����"+letters[i]+"�����(Letter)\n";
	return msg;
}

void init()
{
		add_action("do_sendmail","send");
}

int do_sendmail(string arg)
{
	int i;
	object me,master;
	string name,*letters;
	if(!arg) return notify_fail("�÷���send letter to ĳ��\n");
	if (sscanf(arg, "letter to %s", name)!=1)
		return notify_fail("�÷���send letter to ĳ��\n");
	me=this_player();
	if( !(master=present(name,environment(me))))
		return notify_fail("����û������ˡ�\n");
	letters=query("letters");
	for(i=0;i<sizeof(letters);i++)
		if( letters[i]==master->query("name") && !userp(master))	// annie. 
			{
				if(sizeof(letters)==1)
					letters=0;
				else if(i==0)
					letters=letters[1..sizeof(letters)-1];
				else
					letters=letters[0..i-1]+letters[i+1..sizeof(letters)-1];
				set("letters",letters);
				switch (random(3)){
				case 0:
				message_vision("$NĨ�˰Ѻ�,����$nһ�����\n",me,master);
				break;
				case 1:
				message_vision("$N�˸߲��ҵؽ���$nһ�����\n",me, master);
				break;
				case 2:
				message_vision("$N���������ذ�һ���������$n��\n",me,master);
				}
				switch (master->query("name"))
				{
				case "�����ʦ":
				case "�λ���ʦ":
				case "�˹���ʦ":
 				case "����"	:
				message_vision("$N΢Ц�ŵ��˵�ͷ,˵��:��λʩ���������ˡ�\n",master);
				break;
				case "������":
				case "ѩ���":
				message_vision("$N��ȻһЦ����λ"+ RANK_D->query_respect(me)+",����̫лл���ˡ�\n",master);
				break;
				case "�Ϲٽ��":
				case "���Ŵ�ѩ":
				message_vision("$N���쳤Ц����һ���������ˡ�\n",master);
				break;
				case "�����":
				message_vision("$N�ߵ�����Ҷ�϶�����Ȼ�����Ϸ�֮ǰ��̤��ԭ��\n",master);
				break;
				break;
				case "���˷�":
				case  "ʯ��":
				message_vision("$N̾�˿��������Ǻο��أ����ȥ�ɡ�\n",master);
				break;
				case "κ����": 
				case "�ϵ�����":
				case "�����" :
				case "��ڤͨ��":
				message_vision("$N������һЦ����$n˵������֪���ˡ���\n",master,me);
				break;
				break;
				case  HIY"�������"NOR:
				message_vision("$NЦ�������˼�ľۻᣬҲ���뵽�ң����������ˡ�\n",master);
				break;
				case  HIY"�������"NOR :
				message_vision("$N΢Ц�ŵ��˵�ͷ��̾�˿����������ˣ����ˡ���\n",master);
				break;
				case  "����" :
				case  "���촸" :
				message_vision("$N������Ц����Ҷ�϶����ǵ��Ϸ�һ��ȥ������\n",master);
				break;
				case "ʯ����":
				case "ˮĸ����":
				message_vision("$N������ź�����Ȥ���Ǻܴ󣬵��˵�ͷ������$n�����ˡ�\n",master,me);
				break;
				case "������":
				case "��Ѱ��":
				case "����" :
				message_vision("$N����������ţ���$n˵��������Ҷ���������п�һ��ȥ��������λ"+RANK_D->query_respect(me)+"�ˡ���\n",master,me);
				break;
				case "������":
				message_vision("$N����ü�������ţ���˼��һ�󣬻��ֵ���������֪���ˣ�����ȥ�ɡ���\n",master);
				break;
				default :
				switch(random(6)) 
						{
					case 0:
                        message_vision("$N��Цһ����������ɣ�����һЦ����һ��ȵúÿడ��\n", master);
						break;
					case 1:
                        message_vision("$N����������Բ֮ҹ���Ͻ�֮�ۣ�����˭�����µ�һ���أ�\n",master);
						break;
					case 2:
						message_vision("$N���һ��������мһ�ˡ�\n", master);
						break;
					case 3:
                        message_vision("$N��̾һ������������ʮ��Ľ�������Ҫ��ʼ������ô��Ҷ�³ǡ������򵥰���\n",master);
						break;
					case 4:
						message_vision("$N��������˼һ�������Ŵ��⣬�����˴���\n",master);
						break;
					case 5:
                        message_vision(CYN"$N��ü����ĳ����ҹ��������΢�ǹ�󰵣��Ƿ��д��ֽ�����\n"NOR, master);
						}
						
				}
				return 1;
			}
	return notify_fail("��û�и�"+master->query("name")+"�����\n");
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
