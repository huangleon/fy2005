inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "xu yun","lanwood","sinny","sing girl" }) );
        set("gender", "Ů��" );
        set("age", 31);
        set("title", CYN"��԰�߽�֮"NOR);
        set("nickname", MAG"������������ǳ"NOR);
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void do_ggyy(int count)
{
        object me;
        string msg;
		object room;
        string *event_msg = ({

CYN"\nֻ���ú�Ļ����̨��ת�������ɡ�\n"NOR,
CYN"ֻ��һ��������磬��ͤ����Զ������\n"NOR,

MAG"��һ��¯�зٱ��㣬���޾پ��������\n"NOR,
MAG"���������������ϣ������������Ѿ�����\n"NOR,
MAG"���ֲ��������ʣ��ŵ������������r��\n"NOR,
MAG"��ֻ˵������ħ�ϣ�ȴԭ�����������顣\n"NOR,
MAG"�����������ڽ�ͤ�ϣ�����׳��ʤǮ����\n"NOR,

CYN"\nֻ��̨Ļ��һת�������Ůҡ�ִ���\n"NOR,
CYN"���沨������������Ů�Ӻ�������\n"NOR,

WHT"�Ĺ˵ó������˸ߣ�"NOR,
WHT"ͺ¿���Ҷ����ã�"NOR,
WHT"��ƭ���ɰѺ���ס�\n"NOR,
WHT"һȥ�����޼ұ������ն���ｻ��\n"NOR,
WHT"����ɽ����������ҧ��������Ұ���ҡ��\n"NOR,
WHT"˲�䱦��˫���ʣ���ס��ͺ¿��Ī���ģ�\n"NOR,

CYN"\n����ת���Ƴ�һ�ˣ����ɮЬ�Ǻ��У�\n"NOR,
YEL"�ʲŴ�������Ժ��\n"NOR,
YEL"���ѷ��������ɡ�\n"NOR,
YEL"��֪����ħ��������\n"NOR,
YEL"����һ����һ�ԡ�\n"NOR,

WHT"\n����������������һ����������ɽ����Ը��ԧ�졣\n"NOR,
WHT"����ʦ����������ɷţ��ҷ��޽���λ�����������\n"NOR,

YEL"\n�����������Ǹߵº��У�������ħŮƥ���ˣ�\n"NOR,
YEL"��Ȱ�����ת����ɽ�ϣ������ǻ��˼����������\n"NOR,

CYN"\nֻ��������Ů��ҧ�������ſھͽ������\n"NOR,

BLU"��һ�Բ�����ŭ��ǧ�ɣ���һ����ƥ����ϸ�����꣺\n"NOR,
BLU"��С�������ɸ���򳪣���ƥ����������ɢԧ�졣\n"NOR,
BLU"�ų���������²������������ٳ���ˮӿ������\n"NOR,

WHT"\nС����Դ�³������״�����ȵ�����ʦ���ƺ���\n"NOR,
WHT"������������ƽ�ȹ��������е������߹��������\n"NOR,
WHT"�ں��Ͻ���Եͬ�����ϣ������ɻ����˾��¶��ɡ�\n"NOR,
WHT"�����Ұ���������һ�룬�����˴��ľͻ������ɡ�\n"NOR,

YEL"\n�������ݵ�Ҫ�������룬�����ɳ����ǵ���������\n"NOR,
YEL"���������ݵú������ϣ���Ҳ�������ı���������\n"NOR,

WHT"\n�������ƶ��ǧ�����ϣ������˶����̰������\n"NOR,
WHT"Ҳ��֪˭���Ǻ������ϣ������ҷ��������·��š�\n"NOR,

YEL"\n��֪��ɮ���������ȣ���������ħ�����ѵ�ǿ��\n"NOR,

WHT"\n����ʦ�������������ȣ����е��������������ã�\n"NOR,

BLU"\n��������������������������ǽ�������־��á�\n"NOR,

YEL"\n�����н�һ��������!�������������������ã�\n"NOR,

CYN"\n��Ļ�������£�ԭ������Ϸ�����սᡣ\n"NOR,
});
        me = this_object();
        msg = event_msg[count];
//        message_vision(msg,me);
		room = find_object("/d/fy/theater");
		if (!room)
			room = load_object("/d/fy/theater");
		tell_room(room,msg);
		if (count < sizeof(event_msg)-1)
                call_out("do_ggyy",1+random(2),count+1);
        return;

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

