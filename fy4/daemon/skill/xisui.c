inherit SKILL;
void setup(){
	set("name","ϴ�辭");
	set("type","iron-cloth");
	set("skill_class","shaolin");
	set("effective_level",200);
	
	set("difficulty",200);
	set("usage/iron-cloth",1);
	set("bounce_ratio",8);
	set("ic_effect",50);
	
	set("absorb_msg", ({
        	"$N����ܸһ�ɴ�����$n���Ϸ���������\n",
        	"$nȫ��������̥���ǣ�һ�ɵ���������$N��\n",
	}) );	
}


int help(object me)
{
	write(@HELP   
L120 ���׽������yijinjue������5������
HELP
    );
    return 1;
}
